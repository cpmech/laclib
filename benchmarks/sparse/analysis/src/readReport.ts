import fs from 'fs';
import { checkType } from '@cpmech/js2ts';
import { IReport, PlatToolset, zeroReport } from './types';

const RESDIR = '../results';
const ADDR = 'https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results';

export const readReport = (fnkey: string, toolset: PlatToolset = 'open'): IReport => {
  const dataJson = fs.readFileSync(`${RESDIR}/${toolset}/${fnkey}.json`, 'utf8');
  const dataObject = JSON.parse(dataJson);
  const report = checkType(zeroReport(), dataObject, { link: true });
  if (!report) {
    throw 'cannot parse report';
  }
  report.link = `${ADDR}/${toolset}/${fnkey}.txt`;
  return report;
};
