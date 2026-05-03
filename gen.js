const fs = require('fs');
const simpleGit = require('simple-git');
const moment = require('moment');

const git = simpleGit();
// Hardcoded strictly to your requested dates
const START_DATE = '2026-02-01T12:00:00'; 
const END_DATE = '2026-05-03T12:00:00';

const generateExactRangeStreak = async () => {
    let currentDate = moment(START_DATE);
    const endDate = moment(END_DATE);
    let dayCount = 1;
    const TOTAL_FILES = 100;

    console.log(`🚀 Building streak strictly from Feb 1 to May 3 for new repo...`);

    // Phase 1: One file per day from Feb 1 to May 3
    while (currentDate.isSameOrBefore(endDate)) {
        const dateString = currentDate.format('YYYY-MM-DDTHH:mm:ss');
        await commitFile(dayCount, dateString);
        
        dayCount++;
        currentDate.add(1, 'days');
    }

    // Phase 2: Committing remaining files on the final day (May 3)
    console.log(`\n📦 Reached May 3. Committing any remaining files...`);
    const finalDateString = endDate.format('YYYY-MM-DDTHH:mm:ss');

    while (dayCount <= TOTAL_FILES) {
        await commitFile(dayCount, finalDateString);
        dayCount++;
    }

    await git.add('.');
    await git.env('GIT_COMMITTER_DATE', finalDateString).commit(`Add remaining configs`, { '--date': finalDateString });

    console.log('🎉 Done! 100 files committed exactly between Feb 1 and May 3.');
};

// Helper function to find and commit the files
const commitFile = async (num, dateString) => {
    // UPDATED: Now looks for all the new file formats (q1, q12.cc, Q37, Q049, Day 76, etc.)
    const possibleFiles = [
        `Day ${num}.c`, 
        `Day  ${num}.c`, 
        `Day${num}.c`,
        `q${num}.c`,
        `q${num}.cc`,
        `Q${num}.c`,
        `Q0${num}.c`
    ];
    
    let foundFile = null;

    for (const file of possibleFiles) {
        if (fs.existsSync(`./${file}`)) {
            foundFile = file;
            break;
        }
    }

    try {
        if (foundFile) {
            await git.add(foundFile);
            await git.env('GIT_COMMITTER_DATE', dateString).commit(`Add ${foundFile}`, { '--date': dateString });
            console.log(`✅ ${moment(dateString).format('MMM DD')}: Committed -> ${foundFile}`);
        } else {
            fs.writeFileSync('./streak.md', `Streak maintained for Day ${num}\n`, { flag: 'a' });
            await git.add('./streak.md');
            await git.env('GIT_COMMITTER_DATE', dateString).commit(`Maintain daily practice streak`, { '--date': dateString });
            console.log(`🟩 ${moment(dateString).format('MMM DD')}: Kept streak alive (No file found for Day ${num})`);
        }
    } catch (error) {
        console.error(`❌ Error on ${dateString}:`, error);
    }
};

generateExactRangeStreak();