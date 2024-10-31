from __future__ import annotations

import os
import secrets

from dotenv import load_dotenv

load_dotenv()

DEBUG = bool(int(os.getenv("DEBUG", "1")))
SECRET_KEY = os.getenv("SECRET_KEY", secrets.token_urlsafe(16))
SQLALCHEMY_DATABASE_URI = os.getenv("SQLALCHEMY_DATABASE_URI", "sqlite:///site.db")
SQLALCHEMY_TRACK_MODIFICATIONS = True
SQLALCHEMY_RECORD_QUERIES = True
SQLALCHEMY_ENGINE_OPTIONS = {"pool_pre_ping": True}
SQLALCHEMY_POOL_SIZE = 5
SQLALCHEMY_POOL_TIMEOUT = 30

SECURITY_PASSWORD_SALT = os.getenv("SECURITY_PASSWORD_SALT", secrets.token_urlsafe(16))
REMEMBER_COOKIE_SAMESITE = "strict"
SESSION_COOKIE_SAMESITE = "strict"

TEMPLATES_AUTO_RELOAD = True
