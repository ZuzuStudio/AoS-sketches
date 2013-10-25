#include "levelofdetalisation.h"

LevelOfDetalisation::LevelOfDetalisation(QString fileName, double upperLimit, double downLimit):
    rendererField(nullptr),
    upperLimitField(upperLimit),
    downLimitField(downLimit)
{
    rendererField = new QSvgRenderer(fileName);
}

LevelOfDetalisation::~LevelOfDetalisation() noexcept
{
    delete rendererField;
    rendererField = 0; //nullptr;
}
