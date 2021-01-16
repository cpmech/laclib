import { formatLongNumber } from '@cpmech/util';
import { genTable } from './genTable';
import { readReport } from './readReport';

const fmtNum = (n: number): string => formatLongNumber(n.toString());

async function run() {
  const matrices: string[] = [
    'inline_1',
    'Flan_1565',
    'pre2',
    'av41092',
    'bfwb62',
    'helm2d03',
    'oilpan',
    'tmt_unsym',
    'twotone',
  ];

  const nums: number[] = [1, 2, 3, 4];

  matrices.forEach((mat) => {
    const mpiReports = nums.map((n) => readReport(mat, n));
    const ompReports = nums.map((n) => readReport(mat, 1, n));
    const mpiTable = genTable(mat, mpiReports);
    const ompTable = genTable(mat, ompReports, true);
    const r0 = mpiReports[0];
    const strSym = r0.Symmetric ? 'Symmetric matrix' : 'General matrix (unsymmetric)';
    const readme = `## ${mat} matrix

Reference: https://sparse.tamu.edu/Janna/${mat}

* ${strSym}
* Dimension = ${fmtNum(r0.NumberOfRows)}
* Number of non-zero values = ${fmtNum(r0.NumberOfNonZeros)}

_MPI results:_

${mpiTable}

_OpenMP results:_

${ompTable}

`;
    console.log(readme);
  });
}

(async () => {
  try {
    await run();
  } catch (e) {
    console.log(e);
  }
})();
