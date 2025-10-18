const fetch = require('node-fetch');

exports.handler = async (event) => {
  if (event.httpMethod !== 'POST') {
    return { statusCode: 405, body: 'Method Not Allowed' };
  }

  try {
    const body = JSON.parse(event.body || '{}');
    const code = body.code || '';
    const stdin = body.stdin || '';
    const language_id = body.language_id || 54; // 54 = C++

    if (!code) return { statusCode: 400, body: JSON.stringify({ error: 'No code provided' }) };

    const source_b64 = Buffer.from(code, 'utf8').toString('base64');
    const payload = {
      source_code: source_b64,
      language_id: language_id
    };
    if (stdin) payload.stdin = Buffer.from(stdin, 'utf8').toString('base64');

    const JUDGE0_URL = process.env.JUDGE0_URL || 'https://ce.judge0.com/submissions?base64_encoded=true&wait=true';
    const headers = { 'Content-Type': 'application/json' };
    if (process.env.JUDGE0_API_KEY) headers['X-Auth-Token'] = process.env.JUDGE0_API_KEY;

    const resp = await fetch(JUDGE0_URL, {
      method: 'POST',
      headers,
      body: JSON.stringify(payload)
    });

    const data = await resp.json();

    return {
      statusCode: 200,
      headers: {
        'Content-Type': 'application/json',
        'Access-Control-Allow-Origin': '*'
      },
      body: JSON.stringify(data)
    };

  } catch (err) {
    return {
      statusCode: 500,
      headers: { 'Access-Control-Allow-Origin': '*' },
      body: JSON.stringify({ error: err.message })
    };
  }
};
