#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from http.server import HTTPServer, SimpleHTTPRequestHandler


class TestServerHandler(SimpleHTTPRequestHandler):
    # Request header handler for default do_GET() path in
    # SimpleHTTPRequestHandler.do_GET(self) below.
    def send_head(self):
        if self.path.endswith('.js'):
            path = self.translate_path(self.path)
            try:
                f = open(path, 'rb')
            except IOError:
                self.send_error(404, "File not found: " + path)
                return None
            self.send_response(200)
            self.send_header('Content-type', 'application/javascript')
            self.send_header('Connection', 'close')
            self.end_headers()
            return f
        else:
            return SimpleHTTPRequestHandler.send_head(self)

    # Add COOP, COEP, CORP, and no-caching headers
    def end_headers(self):
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Cross-Origin-Opener-Policy', 'same-origin')
        self.send_header('Cross-Origin-Embedder-Policy', 'require-corp')
        self.send_header('Cross-Origin-Resource-Policy', 'cross-origin')
        self.send_header(
            'Cache-Control', 'no-cache, no-store, must-revalidate')
        return SimpleHTTPRequestHandler.end_headers(self)


# allows streaming compilation to work
SimpleHTTPRequestHandler.extensions_map['.wasm'] = 'application/wasm'

httpd = HTTPServer(('localhost', 8888), TestServerHandler)
httpd.serve_forever()  # test runner will kill us
