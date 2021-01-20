import fs from 'fs';
import { any2type } from '@cpmech/js2ts';
import { IReport, zeroReport } from './types';

const RESDIR = '../results';
const ADDR = 'https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results';

export const readReport = (fnkey: string, intel = false): IReport => {
  const x = intel ? '/intel' : '/open';
  const dataJson = fs.readFileSync(`${RESDIR}${x}/${fnkey}.json`, 'utf8');
  const dataObject = JSON.parse(dataJson);
  const report = any2type(zeroReport(), dataObject, false, { link: true });
  if (!report) {
    throw 'cannot parse report';
  }
  report.link = `${ADDR}/${x}/${fnkey}.txt`;
  return report;
};
