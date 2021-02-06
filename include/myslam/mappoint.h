//
// Created by matthew on 2021/2/6.
//

#ifndef MYSLAM_MAPPOINT_H
#define MYSLAM_MAPPOINT_H

namespace myslam{
class Frame;
class MapPoint
{
public:
    typedef std::shared_ptr<MapPoint>   Ptr;
    unsigned long                       id_;//ID
    Vector3d                            pos_;//position in world
    Vector3d                            norm_;//Normal of viewingf direction
    Mat                                 descriptor_;//Descripter for matching
    int                                 observed_times_;
    int                                 correct_times_;

    MapPoint();
    MapPoint(long id, Vector3d position, Vector3d norm);
    //
    static MapPoint::Ptr createMapPoint();
};
}
#endif //MYSLAM_MAPPOINT_H
