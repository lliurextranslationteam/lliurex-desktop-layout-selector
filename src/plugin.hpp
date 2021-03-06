/*
    lliurex desktop layout selector

    Copyright (C) 2019  Enrique Medina Gremaldos <quiqueiii@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LLIUREX_DLS_PLUGIN
#define LLIUREX_DLS_PLUGIN

#include <QString>
#include <QObject>

namespace lliurex
{
    namespace dls
    {
        namespace kcm
        {
            class Plugin
            {
                private:
                
                QObject* plugin;
                    
                public:
                    
                Plugin();
                ~Plugin();
                
                QString getSelectedTheme();
                void setTheme(QString name);
                
            };
        }
    }
}

#endif