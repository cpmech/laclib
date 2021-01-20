import { genReadme } from './genReadme';

async function run() {
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
  const readme = genReadme(matrices);
  console.log(readme);
}

(async () => {
  try {
    await run();
  } catch (e) {
    console.log(e);
  }
})();
