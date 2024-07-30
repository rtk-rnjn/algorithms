const multiplyMatrix = (matrix1, matrix2) => {
    const matrixSize = matrix1.length;
    const resultarr = new Array(matrixSize);

    for (let i = 0; i < matrixSize; i++) {
        resultarr[i] = new Array(matrixSize);
    }

    for (let i = 0; i < matrixSize; i++) {
        for (let j = 0; j < matrixSize; j++) {
            resultarr[i][j] = 0;
            for (let k = 0; k < matrixSize; k++) {
                resultarr[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return resultarr;
};

const A = [[1, 2], [3, 4]];
const B = [[1, 2], [3, 4]];
const C = multiplyMatrix(A, B);

console.log(C);
