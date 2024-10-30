from __future__ import annotations

from flask import Flask
from flask_security.core import Security
from flask_security.datastore import SQLAlchemyUserDatastore
from flask_security.models import fsqla_v3 as fsqla
from flask_socketio import SocketIO
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config.from_pyfile("config.py")
socketio = SocketIO(app)

db = SQLAlchemy(app)
fsqla.FsModels.set_db_info(db)

from server.models import *  # noqa

user_datastore = SQLAlchemyUserDatastore(db, User, Role)

security = Security(app, user_datastore)

with app.app_context():
    db.create_all()


from server.routes import *  # noqa
