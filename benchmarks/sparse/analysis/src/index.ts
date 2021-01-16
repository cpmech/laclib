import fs from 'fs';
import { readReport } from './readReport';

async function run() {
  // const report = readReport('bfwb62');
  // console.log(report);
}

(async () => {
  try {
    await run();
  } catch (e) {
    console.log(e);
  }
})();
