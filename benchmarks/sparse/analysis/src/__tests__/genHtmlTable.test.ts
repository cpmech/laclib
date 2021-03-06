import { genHtmlTable } from '../genHtmlTable';
import { IReport, IReportSet, zeroReport, defaultHtmlStyles } from '../types';
import { genHtml } from '../genHtml';

describe('genHtmlTable ', () => {
  const ro: IReport[] = [zeroReport(), zeroReport(), zeroReport(), zeroReport()];
  const ri: IReport[] = [zeroReport(), zeroReport(), zeroReport(), zeroReport()];

  ro[0].StepAnalyze.ElapsedTimeString = '1.1';
  ro[1].StepAnalyze.ElapsedTimeString = '1.2';
  ro[2].StepAnalyze.ElapsedTimeString = '1.3';
  ro[3].StepAnalyze.ElapsedTimeString = '1.4';

  ro[0].StepFactorize.ElapsedTimeString = '2.1';
  ro[1].StepFactorize.ElapsedTimeString = '2.2';
  ro[2].StepFactorize.ElapsedTimeString = '2.3';
  ro[3].StepFactorize.ElapsedTimeString = '2.4';

  ro[0].StepSolve.ElapsedTimeString = '3.1';
  ro[1].StepSolve.ElapsedTimeString = '3.2';
  ro[2].StepSolve.ElapsedTimeString = '3.3';
  ro[3].StepSolve.ElapsedTimeString = '3.4';

  ro[0].TimeSolverString = '4.1';
  ro[1].TimeSolverString = '4.2';
  ro[2].TimeSolverString = '4.3';
  ro[3].TimeSolverString = '4.4';

  ro[0].Stats.NormInfAx = 11.11;
  ro[1].Stats.NormInfAx = 22.22;
  ro[2].Stats.NormInfAx = 33.33;
  ro[3].Stats.NormInfAx = 44.44;

  ro[0].Stats.RelativeError = 0.11;
  ro[1].Stats.RelativeError = 0.22;
  ro[2].Stats.RelativeError = 0.33;
  ro[3].Stats.RelativeError = 0.44;

  ri[0].StepAnalyze.ElapsedTimeString = '11';
  ri[1].StepAnalyze.ElapsedTimeString = '12';
  ri[2].StepAnalyze.ElapsedTimeString = '13';
  ri[3].StepAnalyze.ElapsedTimeString = '14';

  ri[0].StepFactorize.ElapsedTimeString = '21';
  ri[1].StepFactorize.ElapsedTimeString = '22';
  ri[2].StepFactorize.ElapsedTimeString = '23';
  ri[3].StepFactorize.ElapsedTimeString = '24';

  ri[0].StepSolve.ElapsedTimeString = '31';
  ri[1].StepSolve.ElapsedTimeString = '32';
  ri[2].StepSolve.ElapsedTimeString = '33';
  ri[3].StepSolve.ElapsedTimeString = '34';

  ri[0].TimeSolverString = '41';
  ri[1].TimeSolverString = '42';
  ri[2].TimeSolverString = '43';
  ri[3].TimeSolverString = '44';

  ri[0].Stats.NormInfAx = 101;
  ri[1].Stats.NormInfAx = 202;
  ri[2].Stats.NormInfAx = 303;
  ri[3].Stats.NormInfAx = 404;

  ri[0].Stats.RelativeError = 0.01;
  ri[1].Stats.RelativeError = 0.02;
  ri[2].Stats.RelativeError = 0.03;
  ri[3].Stats.RelativeError = 0.04;

  it('generates default table', () => {
    const reports: IReportSet = {
      open: { reports: ro },
      intel: { reports: ri },
    };
    const table = genHtmlTable('mytableX', reports, ['Analyze', 'Factorize'], defaultHtmlStyles());
    expect(table).toMatchSnapshot();

    // debugging
    const filepath = '/tmp/laclib/table.html';
    genHtml(filepath, 'laclib table', table);
  });

  it('generates small table', () => {
    const r = zeroReport();
    r.StepAnalyze.ElapsedTimeString = '1s';
    r.StepFactorize.ElapsedTimeString = '2s';
    r.StepSolve.ElapsedTimeString = '3s';
    r.TimeSolverString = '6s';
    const reports: IReport[] = [r, r, r, r];
    const reportSet = { intel: { reports } };
    const table = genHtmlTable('mytable', reportSet, ['Analyze', 'Factorize'], defaultHtmlStyles());
    expect(table).toMatchSnapshot();
  });
});
