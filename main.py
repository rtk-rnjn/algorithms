from __future__ import annotations

import asyncio
import os

import uvicorn
from asgiref.wsgi import WsgiToAsgi

from server import app

if os.name == "nt":
    asyncio.set_event_loop_policy(asyncio.WindowsSelectorEventLoopPolicy())
else:
    try:
        import uvloop

        asyncio.set_event_loop_policy(uvloop.EventLoopPolicy())
    except ImportError:
        asyncio.set_event_loop_policy(asyncio.DefaultEventLoopPolicy())

asgi_app = WsgiToAsgi(app)


if __name__ == "__main__":
    uvicorn.run(asgi_app, host="0.0.0.0", port=8000, log_level="debug")
