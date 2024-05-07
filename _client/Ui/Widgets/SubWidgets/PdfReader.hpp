#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPdfView>
#include <QPdfDocument>
#include <QPdfSearchModel>

#include "SearchFieldComp.hpp"

class PdfReader : public QWidget
{
    Q_OBJECT
public:
    PdfReader(QWidget *parent = nullptr);
    ~PdfReader();

    void init();
    void openPdf(QPdfDocument *document);

signals:
    void emitExit();

protected slots:
    void onExitButtonClicked();

private:
    QVBoxLayout *m_layout;
    QPdfView *m_view;
    QPushButton *m_exitButton;

    SearchFieldComp *m_searchField;
};