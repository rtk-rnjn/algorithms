const rabinKarp = (text, pattern) => {
    const textLength = text.length;
    const patternLength = pattern.length;
    const d = 256;
    const q = 101;
    let i;
    let j;
    let p = 0;

    let t = 0;
    let h = 1;
    let found = false;

    for (i = 0; i < patternLength - 1; i++) {
        h = (h * d) % q;
    }

    for (i = 0; i < patternLength; i++) {
        p = (d * p + pattern.charCodeAt(i)) % q;
        t = (d * t + text.charCodeAt(i)) % q;
    }

    for (i = 0; i <= textLength - patternLength; i++) {
        if (p === t) {
            for (j = 0; j < patternLength; j++) {
                if (text[i + j] !== pattern[j]) {
                    break;
                }
            }
            if (j === patternLength) {
                console.log(`Pattern found at index ${i}`);
                found = true;
            }
        }

        if (i < textLength - patternLength) {
            t = (d * (t - text.charCodeAt(i) * h) + text.charCodeAt(i + patternLength)) % q;
            if (t < 0) {
                t += q;
            }
        }
    }

    if (!found) {
        console.log('Pattern not found');
    }

}

const text = 'AABAACAADAABAAABAA';
const pattern = 'AABA';

rabinKarp(text, pattern);