//#ifndef PROJECTOR_H
//#define PROJECTOR_H

//#include <gdal_priv.h>
//#include <ogr_spatialref.h>
//#include<QPointF>
//#include"../../../core/shapes.h"
//namespace Prj {
//enum prj{
//    //web墨卡托投影
//    WGS84
//};
//}
//class Projector
//{
//public:
//    Projector()
//    {
//        // 注册所有的GDAL驱动
//        GDALAllRegister();
//    }
//    static Projector* makeProjector(Prj::prj prj_type)
//    {

//    }

//    virtual QPointF prj(Point) = 0;
//    virtual ~Projector()
//    {
//        // 释放资源
//        OCTDestroyCoordinateTransformation(coordTransform);
//    }
//protected:
//    OGRCoordinateTransformation* coordTransform;
//};
//class WGS84:public Projector
//{
//public:
//    WGS84()
//    {
//        // 定义Web墨卡托投影的EPSG代码（3857）
//        const char* targetProjection = "EPSG:3857";

//        // 创建一个空间参考对象，并设置输入经纬度坐标的空间参考为WGS84
//        OGRSpatialReference inputSRS;
//        inputSRS.SetWellKnownGeogCS("WGS84");

//        // 创建一个空间参考对象，并设置目标投影的空间参考
//        OGRSpatialReference targetSRS;
//        targetSRS.SetFromUserInput(targetProjection);

//        coordTransform = OGRCreateCoordinateTransformation(&inputSRS, &targetSRS);
//    }
//    static Projector* Factory()
//    {
//        return new WGS84();
//    }

//    QPointF prj(Point p )
//    {
//        OGRPoint inputPoint(p.x, p.y);
//        // 进行投影转换
//            if (coordTransform->Transform(1, &inputPoint) != 0) {
//                // 获取转换后的墨卡托投影坐标
//                double targetX = inputPoint.getX();
//                double targetY = inputPoint.getY();

//                // 打印转换结果
//                printf("Web墨卡托投影坐标: X=%f, Y=%f\n", targetX, targetY);
//            } else {
//                // 处理坐标转换错误
//                printf("坐标转换错误\n");
//            }
//    }
//    ~WGS84()
//    {

//    }
//};

//#endif // PROJECTOR_H
