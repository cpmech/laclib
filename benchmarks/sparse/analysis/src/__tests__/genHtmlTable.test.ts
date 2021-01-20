import { genHtmlTable } from '../genHtmlTable';
import { IReport, zeroReport } from '../types';

describe('genHtmlTable', () => {
  it('generates default table', () => {
    const r = zeroReport();
    r.StepAnalyze.ElapsedTimeString = '1s';
    r.StepFactorize.ElapsedTimeString = '2s';
    r.StepSolve.ElapsedTimeString = '3s';
    r.TimeSolverString = '6s';
    const reports: IReport[] = [r, r, r, r];
    const table = genHtmlTable('mytable', reports);
    expect(table).toMatchSnapshot();
  });

  it('generates OMP table', () => {
    const r = zeroReport();
    r.StepAnalyze.ElapsedTimeString = '1s';
    r.StepFactorize.ElapsedTimeString = '2s';
    r.StepSolve.ElapsedTimeString = '3s';
    r.TimeSolverString = '6s';
    const reports: IReport[] = [r, r, r, r];
    const table = genHtmlTable('mytable', reports, true);
    expect(table).toMatchSnapshot();
  });
});
