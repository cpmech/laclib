import { readReport } from '../readReport';

describe('readReport', () => {
  it('reads bfwb62', () => {
    const rpt = readReport('mumps_bfwb62_metis_open_seq');
    expect(rpt).toMatchSnapshot();
  });

  it('fails due to wrong matrixName', () => {
    expect(() => {
      readReport('mumps_nada_metis_mpi1');
    }).toThrowError(
      "ENOENT: no such file or directory, open '../results/open/mumps_nada_metis_mpi1.json'",
    );
  });
});
