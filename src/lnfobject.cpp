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

#include "lnfobject.hpp"

#include <QDebug>

using namespace lliurex::dls;

LNF::LNF(QObject* parent)
{
    plugin = new kcm::Plugin();
    
    QString themeName=plugin->getSelectedTheme();
    
    qDebug()<<"current theme: "<<themeName;
    
    packages.append(new Package("Default","lliurex-desktop"));
    packages.append(new Package("Classic","lliurex-desktop-classic"));
    
    index=0;
    currentIndex=-1;
    
    for (int n=0;n<packages.count();n++) {
        Package* package = static_cast<Package*>(packages[n]);
        
        if (package->path==themeName) {
            currentIndex=n;
            index=currentIndex;
            qDebug()<<"current index: "<<n;
        }
    }
}

LNF::~LNF()
{
    delete plugin;
}

void LNF::setTheme(QString theme)
{
    plugin->setTheme(theme);
}