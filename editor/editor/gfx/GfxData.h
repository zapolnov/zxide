#ifndef EDITOR_GFX_GFXDATA_H
#define EDITOR_GFX_GFXDATA_H

#include <QObject>
#include <QPoint>
#include <memory>

enum class GfxColorMode : int
{
    Standard,
    Multicolor,
    Bicolor,
};

class GfxData : public QObject
{
    Q_OBJECT

public:
    explicit GfxData(int w, int h, QObject* parent = nullptr);
    ~GfxData() override;

    int width() const { return mWidth; }
    int height() const { return mHeight; }
    void resize(int w, int h);

    bool isValidCoord(int x, int y) const;
    bool isValidCoord(const QPoint& pt) const;

    char at(int x, int y) const;
    char at(const QPoint& p) const;
    char& at(int x, int y);
    char& at(const QPoint& p);

    char attribAt(int x, int y, GfxColorMode mode) const;
    char& attribAt(int x, int y, GfxColorMode mode);

    void clear();
    void clear(int x1, int y1, int x2, int y2);

    QByteArray bytes() const;
    QByteArray bytes(int x1, int y1, int x2, int y2) const;
    QByteArray attrib(int x1, int y1, int x2, int y2) const;

    void setBytes(const QByteArray& data);
    void setBytes(int x, int y, int w, int h, const QByteArray& data);
    void setAttrib(int x, int y, int w, int h, const QByteArray& data);

signals:
    void sizeChanged();

private:
    std::unique_ptr<char[]> mData;
    std::unique_ptr<char[]> mAttrib;
    int mWidth;
    int mHeight;

    Q_DISABLE_COPY(GfxData)
};

#endif
