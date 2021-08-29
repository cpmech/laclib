import fs from 'fs';
import { checkType } from '@cpmech/js2ts';
import { IReport, zeroReport } from './types';

const RESDIR = '../results';
const ADDR = 'https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results';

export const readReport = (fnkey: string, subDir = 'latest'): IReport => {
  const dataJson = fs.readFileSync(`${RESDIR}/${subDir}/${fnkey}.json`, 'utf8');
  const dataObject = JSON.parse(dataJson);
  const report = checkType(zeroReport(), dataObject, { link: true });
  if (!report) {
    throw 'cannot parse report';
  }
  report.link = `${ADDR}/${subDir}/${fnkey}.txt`;
  return report;
};
