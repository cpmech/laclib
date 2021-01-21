import { PlatToolset, PlatOption, TableField } from './types';
import { genReadme } from './genReadme';

const matrices: string[] = [
  'inline_1',
  'Flan_1565',
  'pre2',
  'tmt_unsym',
  'bfwb62',
  // 'av41092',
  // 'helm2d03',
  // 'oilpan',
  // 'twotone',
];

async function run() {
  const args = process.argv.slice(2);
  const selection = args.length > 0 ? args[0] : '';

  let toolsets: PlatToolset[] = ['open'];
  let options: PlatOption[] = ['seq_omp#'];
  let fields: TableField[] = ['Analyze', 'Factorize', 'Solve', 'Total', 'Norm(A.x)', 'Rel Error'];

  switch (selection) {
    case 'open_seq_ana_fact_total':
      toolsets = ['open'];
      options = ['seq_omp#'];
      fields = ['Analyze', 'Factorize', 'Total'];
      break;

    case 'open_mpionly_ana_fact_total':
      toolsets = ['open'];
      options = ['mpi#'];
      fields = ['Analyze', 'Factorize', 'Total'];
      break;

    case 'open_mpi1_omp_fact_problem':
      toolsets = ['open'];
      options = ['mpi1_omp#'];
      fields = ['Factorize'];
      break;

    case 'open_intel_all_fact':
      toolsets = ['open', 'intel'];
      options = ['seq_omp#', 'mpi1_omp#', 'mpi#', 'mpi#_omp1', 'mpi#_omp#'];
      fields = ['Factorize'];
      break;

    default:
      throw new Error('case is not available');
  }

  const readme = genReadme(matrices, toolsets, options, fields);

  console.log(readme);
}

(async () => {
  try {
    await run();
  } catch (e) {
    console.log(e);
  }
})();
