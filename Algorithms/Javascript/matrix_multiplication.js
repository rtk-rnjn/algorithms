const MM = (arr1,arr2) => {
    const n = arr1.length;
    const resultarr = new Array(n);
    for (let i = 0; i < n; i++) {
        resultarr[i] = new Array(n);
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            resultarr[i][j] = 0;
            for (let k = 0; k < n; k++) {
                resultarr[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return resultarr;
};

const A = [[1,2],[3,4]];
const B = [[1,2],[3,4]];
const C = MM(A,B);
console.log(C);
