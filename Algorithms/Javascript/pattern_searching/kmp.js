const computeLPSArray = (pattern) => {
    const m = pattern.length;
    const lps = new Array(m).fill(0);

    let len = 0;
    let i = 1;

    while (i < m) {
        if (pattern[i] === pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len !== 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}

const kmp = (text, pattern) => {
    const n = text.length;
    const m = pattern.length;
    const lps = computeLPSArray(pattern);

    let i = 0;
    let j = 0;

    while (i < n) {
        if (text[i] === pattern[j]) {
            i++;
            j++;
        }

        if (j === m) {
            console.log(`Pattern found at index ${i - j}`);
            j = lps[j - 1];
        } else if (i < n && text[i] !== pattern[j]) {
            if (j !== 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

const text = 'AABAACAADAABAAABAA';
const pattern = 'AABA';

kmp(text, pattern);
