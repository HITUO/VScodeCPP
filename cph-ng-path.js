// CPH-NG 自定义路径脚本
// 洛谷 -> .luogu-code/
// Codeforces -> .codeforces-code/
// AtCoder -> .atcoder-code/
// 其他 -> .other-code/

const process = async () => {
  if (!workspaceFolders || workspaceFolders.length === 0) {
    return 'No workspace folder found';
  }

  let folder = workspaceFolders[0].path;
  if (workspaceFolders.length > 1) {
    const selectedFolderName = await ui.chooseItem(
      workspaceFolders.map((f) => f.name),
      'Select a workspace folder to create files in',
    );
    if (selectedFolderName === undefined) {
      return 'No workspace folder selected';
    }
    const selectedFolder = workspaceFolders.find(
      (f) => f.name === selectedFolderName,
    );
    if (!selectedFolder) {
      return 'Selected workspace folder not found';
    }
    folder = selectedFolder.path;
  }

  const ext = 'cpp';
  const results = [];
  logger.debug('Custom path script started', { problems });

  for (const problem of problems) {
    try {
      const { name, url } = problem;
      let filename = null;
      let subdir = '.other-code';

      if (url) {
        try {
          const u = new URL(url);
          const isHost = (host) =>
            u.hostname === host || u.hostname.endsWith(`.${host}`);

          // Codeforces
          if (isHost('codeforces.com')) {
            subdir = '.codeforces-code';
            const regexPatterns = [
              /\/contest\/(\d+)\/problem\/(\w+)/,
              /\/problemset\/problem\/(\d+)\/(\w+)/,
              /\/gym\/(\d+)\/problem\/(\w+)/,
            ];
            for (const regex of regexPatterns) {
              const match = url.match(regex);
              if (match) {
                filename = `${match[1]}${match[2]}.${ext}`;
                logger.info('Detected Codeforces URL', { url, filename, subdir });
                break;
              }
            }
          }

          // 洛谷
          if (!filename && isHost('luogu.com.cn')) {
            subdir = '.luogu-code';
            const match = url.match(/problem\/(\w+)/);
            if (match) {
              filename = `${match[1]}.${ext}`;
              logger.info('Detected Luogu URL', { url, filename, subdir });
            }
          }

          // AtCoder
          if (!filename && isHost('atcoder.jp')) {
            subdir = '.atcoder-code';
            const match = url.match(/tasks\/(\w+)_(\w+)/);
            if (match) {
              filename = `${match[1]}${match[2]}.${ext}`;
              logger.info('Detected AtCoder URL', { url, filename, subdir });
            }
          }
        } catch (e) {
          logger.error('URL Parsing error:', e.message);
        }
      }

      if (!filename) {
        const words = name.match(/[\p{L}]+|[0-9]+/gu);
        const base = words ? words.join('_') : name.replace(/\W+/g, '_');
        filename = `${base}.${ext}`;
        logger.info('Falling back to title-based name', { name, filename, subdir });
      }

      // 构建完整路径：folder/subdir/filename
      const fullPath = path.join(folder, subdir, filename);
      logger.debug('Generated file path', { fullPath });
      results.push(fullPath);
    } catch (e) {
      logger.error(
        'Error generating filename for problem',
        e && e.message ? e.message : e,
      );
      results.push(null);
    }
  }

  logger.debug('Custom path script finished', { results });
  return results;
};
