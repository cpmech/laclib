import { readReport } from './readReport';

describe('readReport', () => {
  it('reads bfwb62', () => {
    const rpt = readReport('mumps_bfwb62_metis_mpi1');
    expect(rpt).toMatchSnapshot();
  });

  it('fails due to wrong matrixName', () => {
    expect(() => {
      readReport('mumps_nada_metis_mpi1');
    }).toThrowError(
      "ENOENT: no such file or directory, open '../results/mumps_nada_metis_mpi1.json'",
    );
  });
});