import { genTable } from './genTable';
import { readReport } from './readReport';

async function run() {
  const matrices: string[] = [
    'av41092',
    'bfwb62',
    'Flan_1565',
    'helm2d03',
    'inline_1',
    'oilpan',
    'pre2',
    'tmt_unsym',
    'twotone',
  ];

  const nums: number[] = [1, 2, 3, 4];

  matrices.forEach((mat) => {
    const mpiReports = nums.map((n) => readReport(mat, n));
    const ompReports = nums.map((n) => readReport(mat, 1, n));
    const mpiTable = genTable(mat, mpiReports);
    const ompTable = genTable(mat, ompReports, true);
    console.log(`## ${mat} matrix\n`);
    console.log('### MPI\n');
    console.log(mpiTable);
    console.log('### OpenMP\n');
    console.log(ompTable);
    console.log('\n\n');
  });
}

(async () => {
  try {
    await run();
  } catch (e) {
    console.log(e);
  }
})();
