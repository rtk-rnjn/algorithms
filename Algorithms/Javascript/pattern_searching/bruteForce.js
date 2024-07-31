const searchPattern = (text, pattern) => {
    const n = text.length;
    const m = pattern.length;
    
    for (let i = 0; i <= n - m; i++) {
        let j;
        for (j = 0; j < m; j++) {
            if (text[i + j] !== pattern[j]) {
                break;
            }
        }
        if (j === m) {
            console.log(`Pattern found at index ${i}`);
        }
    }
}

const text = 'AABAACAADAABAAABAA';
const pattern = 'AABA';

searchPattern(text, pattern);
