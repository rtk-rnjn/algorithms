from __future__ import annotations

import os

from flask import Flask
from flask_security.core import Security
from flask_security.datastore import SQLAlchemyUserDatastore
from flask_security.models import fsqla_v3 as fsqla
from flask_socketio import SocketIO
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy import insert, select

app = Flask(__name__)
app.config.from_pyfile("config.py")
socketio = SocketIO(app)

db = SQLAlchemy(app)
fsqla.FsModels.set_db_info(db)

from server.models import *  # noqa

user_datastore = SQLAlchemyUserDatastore(db, User, Role)

security = Security(app, user_datastore)

VALID = ("py", "java", "cpp", "c", "js", "go")

with app.app_context():
    db.create_all()

    for folder in ("Algorithms", "DataStructures", "CP"):
        for root, _, files in os.walk(folder):
            for file in files:
                if file.endswith(VALID) and not db.session.execute(select(Code).where(Code.filename == file)).fetchone():
                    with open(os.path.join(root, file)) as f:
                        db.session.execute(
                            insert(Code).values(
                                filename=os.path.join(root, file),
                                code=f.read(),
                            ),
                        )

    db.session.commit()

from server.routes import *  # noqa
