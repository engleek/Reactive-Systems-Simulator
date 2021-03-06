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

#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QtGui>
#include <QWidget>
#include <QListWidget>
#include <QString>
#include <QTime>

class ConsoleWidget : public QListWidget {
        Q_OBJECT

    public:
        ConsoleWidget();
        void newMsg(QString message);

    signals:
        void consoleMsg(const QString message);

    public slots:
        void sendMsg(const QString message);

    private:
        //QListWidget* m_console;
};

#endif
