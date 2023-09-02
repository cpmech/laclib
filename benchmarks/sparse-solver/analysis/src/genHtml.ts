import marked from 'marked';
import DOMPurify from 'dompurify';
import { maybeWriteFile } from '@cpmech/basic-sys';

export const genHtml = (
  filepath: string,
  title: string,
  body: string,
  bodyIsMarkdown = false,
  style = '',
  verbose = true,
) => {
  const htmlBody = bodyIsMarkdown ? DOMPurify.sanitize(marked(body, { gfm: true })) : body;
  const html = `<!DOCTYPE html>
<html>
  <head>
    <title>${title}</title>

${style}

  </head>
  <body>

${htmlBody}

  </body>
</html>
`;
  const overwrite = true;
  maybeWriteFile(overwrite, filepath, () => html);
  if (verbose) {
    console.log(`file <${filepath}> written`);
  }
};
