from __future__ import annotations

from flask_security.models import fsqla_v3 as fsqla

from server import db

__all__ = ("Role",)


class Role(db.Model, fsqla.FsRoleMixin):
    pass
