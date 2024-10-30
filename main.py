from __future__ import annotations

from server import app, socketio

if __name__ == "__main__":
    socketio.run(app, debug=True, host="0.0.0.0", port=5000)
