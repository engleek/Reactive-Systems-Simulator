#include <time.h>

#include <QtGui>

#include "mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow()
{
    glWidget = new GLWidget;
    setCentralWidget(glWidget);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    createDocks(); //Ajoute les parties docks

    readSettings();

	//Originalement pour savoir si un document a été modifié. Changer pour voir si simulation en cours.
    //connect(textEdit->document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));

    setCurrentFile("");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	//Une simulation est en cours, confirmation pour quitter.
    if (maybeSave()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::newSim()
{
	//Idem que pour le faite de quitter, on demande.
	/*
    if (maybeSave()) {
        textEdit->clear();
        setCurrentFile("");
    }
    */
}

void MainWindow::open()
{
	//De novo Idem
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
}

bool MainWindow::save()
{
	//A voir. Si la simulation est nouvelle, on fait un saveAs.
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Application"),
            tr("<p>The <b>Reactive Systems Simulator</b>: a total recoding of the CSR Project, with ameliorated GUI and environment, functionality, speed and more.</p>"
               "<p>Compatible with Linux, MacOS and Windows, and any other system capable of compiling C++ code with Qt4 and OpenGL.</p>"
               "<p>This program is open source and released under the GNU General Public License.</p>"
               "<p>For more info visit <a href='http://code.google.com/p/projet-csr-cpp/'>http://code.google.com/p/projet-csr-cpp</a>.</p>"));
}

void MainWindow::documentWasModified()
{
	/*
    setWindowModified(textEdit->document()->isModified());
    */
}

void MainWindow::createActions()
{
	//Actions menu File
    newAct = new QAction(QIcon(":/images/script.png"), tr("&New"), this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(QIcon(":/images/folder_page_white.png"), tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(QIcon(":/images/script_save.png"), tr("&Save"), this);
    saveAct->setShortcut(tr("Ctrl+S"));
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(tr("Save &As..."), this);
    saveAsAct->setStatusTip(tr("Save the document under a new name"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    exitAct = new QAction(QIcon(":/images/door_in.png"), tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    
	//Mise en place provisoire des nouvelles actions, SLOTs et SIGNALs à faire.
	
		//Actions menu Sim
	    runSimAct = new QAction(QIcon(":/images/control_play_blue.png"), tr("&Run"), this);
	    runSimAct->setShortcut(tr("Ctrl+R"));
	    runSimAct->setStatusTip(tr("Run the simulation"));
	
	    restartSimAct = new QAction(QIcon(":/images/control_repeat_blue.png"), tr("R&estart"), this);
	    restartSimAct->setStatusTip(tr("Restart the simulation"));
	
	    resetSimAct = new QAction(QIcon(":/images/control_start_blue.png"), tr("Re&set"), this);
	    resetSimAct->setStatusTip(tr("Reset the simulation"));
	
	    stopSimAct = new QAction(QIcon(":/images/control_play_blue.png"), tr("S&top"), this);
	    stopSimAct->setShortcut(tr("Ctrl+T"));
	    stopSimAct->setStatusTip(tr("Stop the simulation"));
	
		//Actions menu Options
	    fullscreenAct = new QAction(QIcon(":/images/monitor.png"), tr("&Fullscreen"), this);
	    fullscreenAct->setShortcut(tr("Ctrl+F"));
	    fullscreenAct->setStatusTip(tr("Switch to fullscreen simulation"));
	
	    programConfigAct = new QAction(QIcon(":/images/cog.png"), tr("Co&nfigure program"), this);
	    programConfigAct->setStatusTip(tr("Configure the simulator/program"));
	
	    simConfigAct = new QAction(QIcon(":/images/script_gear.png"), tr("Configure simulation"), this);
	    simConfigAct->setStatusTip(tr("Configure the simulation files"));


	//Action menu Help
    aboutAct = new QAction(QIcon(":/images/comment.png"), tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

	//Commentés pour le moment, c'est pas utile.
	/*
    cutAct->setEnabled(false);
    copyAct->setEnabled(false);
    connect(textEdit, SIGNAL(copyAvailable(bool)),
            cutAct, SLOT(setEnabled(bool)));
    connect(textEdit, SIGNAL(copyAvailable(bool)),
            copyAct, SLOT(setEnabled(bool)));
    */
}

void MainWindow::createMenus()
{
	//Creation des menus :P
	//File menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

	//Sim menu
    simMenu = menuBar()->addMenu(tr("&Sim"));
    simMenu->addAction(runSimAct);
    simMenu->addAction(restartSimAct);
    simMenu->addAction(resetSimAct);
    simMenu->addAction(stopSimAct);

	//Options menu
    simMenu = menuBar()->addMenu(tr("&Options"));
    simMenu->addAction(fullscreenAct);
    simMenu->addAction(programConfigAct);
    simMenu->addAction(simConfigAct);

    menuBar()->addSeparator();

	//Help menu
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolBars()
{
	//Creation des toolbars
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);

    simToolBar = addToolBar(tr("Simulation"));
    simToolBar->addAction(runSimAct);
    simToolBar->addAction(restartSimAct);
    simToolBar->addAction(resetSimAct);
    simToolBar->addAction(stopSimAct);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDocks()
{
	//Création de la console
	consoleDock = new QDockWidget(tr("Console"), this);
	consoleDock->setAllowedAreas(Qt::BottomDockWidgetArea
	                              | Qt::TopDockWidgetArea);
	addDockWidget(Qt::BottomDockWidgetArea, consoleDock);
	
	console = new QListWidget(consoleDock);
	consoleDock->setWidget(console);
	
	toConsole(QString("The simulator is up and running..."));
}

void MainWindow::toConsole(const QString &message)
{
	//On met en place les structures de temps
	time_t rawtime;
	struct tm * timeinfo;
	char timeBuffer [11];

	//On s'en sert pour prendre l'heure. Ca sera nécessaire à chaque fois.
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	strftime (timeBuffer,11,"[%X] ",timeinfo);

	console->addItem(QString(timeBuffer)+message);	
}

void MainWindow::readSettings()
{
	//Lecture des paramètres...aucuns pour le moment...on commente!
	/*
    QSettings settings("Trolltech", "Application Example");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
    */
}

void MainWindow::writeSettings()
{
	//Idem
	/*
    QSettings settings("Trolltech", "Application Example");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    */
}

bool MainWindow::maybeSave()
{
	//Pas encore implémenté :P
	/*
    if (textEdit->document()->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Application"),
                     tr("The document has been modified.\n"
                        "Do you want to save your changes?"),
                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    */
    return true;
}

void MainWindow::loadFile(const QString &fileName)
{
	/*
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
    */
}

bool MainWindow::saveFile(const QString &fileName)
{
	/*
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << textEdit->toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    */
    return true;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
	/*
    curFile = fileName;
    textEdit->document()->setModified(false);
    setWindowModified(false);

    QString shownName;
    if (curFile.isEmpty())
        shownName = "untitled.txt";
    else
        shownName = strippedName(curFile);

    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Application")));
    */
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
