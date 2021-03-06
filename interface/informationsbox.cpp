/*******************************************************************************************
 **
 **    Copyright 2008 Simon & Humphries
 **
 **    This file is part of the Reactive Systems Simulator.
 **
 **    The Reactive Systems Simulator is free software: you can redistribute it and/or modify
 **    it under the terms of the GNU General Public License as published by
 **    the Free Software Foundation, either version 3 of the License, or
 **    (at your option) any later version.
 **
 **    The Reactive Systems Simulator is distributed in the hope that it will be useful,
 **    but WITHOUT ANY WARRANTY; without even the implied warranty of
 **    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **    GNU General Public License for more details.
 **
 **    You should have received a copy of the GNU General Public License
 **    along with the Reactive Systems Simulator .  If not, see <http://www.gnu.org/licenses/>.
 **
 ********************************************************************************************/

#include "informationsbox.h"

#include <string>

InformationsBox::InformationsBox()
    : m_currentItem(0)
{
}


InformationsBox::~InformationsBox()
{
}


void InformationsBox::setViewerPointer(Viewer* viewerPointer)
{
    m_viewer = viewerPointer;
}


void InformationsBox::listSet(QStringList infos)
{
    clear();
    addItems(infos);
}


void InformationsBox::setCurrentItem(QTreeWidgetItem* ent, int col)
{
    m_currentItem = ent;
    refreshBox(true);
}


void InformationsBox::refreshBox(bool auto)
{
    if (m_currentItem != 0) {
        clear();
        std::string temp = m_currentItem->text(0).toStdString();

        if (temp == "Camera") {
            addItems(m_viewer->camData());
        } else {
            addItem(m_currentItem->text(0));
            addItem(tr("Sorry, no info on this :'("));
        }
    }
}
