#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H

#include <QProgressBar>

class CustomProgressBar : public QProgressBar
{
    Q_OBJECT

public:
    explicit CustomProgressBar(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QColor m_color;
};

#endif // CUSTOMPROGRESSBAR_H