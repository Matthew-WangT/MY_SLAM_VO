//
// Created by matthew on 2021/2/6.
//

#ifndef FRAME_H
#define FRAME_H
#include "myslam/common_include.h"
#include "myslam/camera.h"
namespace myslam
{
class MapPoint;

class Frame {
public:
    typedef std::shared_ptr<Frame> Ptr;
    unsigned long       id_;            //id of this frame
    double              time_stamp_;    //when it's recorded
    SE3d                T_c_w_;         //transform from world to camera
    Camera::Ptr         camera_;        //RGBD Camera model
    cv::Mat             color_, depth_; //color and depth image
public:
    Frame();
    Frame( long id, double time_stamp=0, SE3d T_c_w=SE3d(),
          Camera::Ptr camera= nullptr, cv::Mat color=Mat(), Mat depth=cv::Mat() );
    ~Frame();
    //Factory function
    static Frame::Ptr createFrame();
    //find the depth in depth map
    double findDepth( const cv::keyPoint& kp );
    //get camera center
    Vector3d getCamCenter() const;
    //check if a point is in this frame
    bool isInFrame( const Vector3d& pt_world );
};
}
#endif //FRAME_H
