#ifndef LEVELOFDETALISATION_H
#define LEVELOFDETALISATION_H

#include <QSvgRenderer>

class LevelOfDetalisation
{
    public:
        LevelOfDetalisation(QString fileName, double upperLimit, double downLimit);
        ~LevelOfDetalisation() noexcept;

        void setUpperLimit(double value)  noexcept {upperLimitField = value;}
        double upperLimit() const noexcept {return upperLimitField;}
        void setDownLimit(double value) noexcept {downLimitField = value;}
        double downLimit() const noexcept {return downLimitField;}
        const QSvgRenderer *renderer() const noexcept {return rendererField;}
    private:
        QSvgRenderer *rendererField;
        double upperLimitField;
        double downLimitField;
};

#endif // LEVELOFDETALISATION_H
