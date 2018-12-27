#ifndef			MAINWINDOW_H_
# define		MAINWINDOW_H_

# include <QStackedWidget>
# include <QWidget>
# include <QTimer>
# include "ordonnanceur.h"
# include "awidget.h"
# include "mozaic.h"

class MainWindow : public QWidget
{
		Q_OBJECT

		QStackedWidget*		widgets_;
		ordonnanceur*     ordonnanceur_;
		Mozaic*						mozaic_;
		QTimer*						timer_;

		MainWindow(MainWindow const& other);
		MainWindow&			operator=(MainWindow const& other);

		void				initTimer();
		void				initWidgets();
		void				initLayout();
		void				initScreen();

	public:
		explicit MainWindow(QWidget *parent = Q_NULLPTR);
		~MainWindow();
		bool				init();
		bool				show();
		bool				run();
		bool				end();

	public slots:
		void				changeWidget();
};

#endif // MAINWINDOW_H_
