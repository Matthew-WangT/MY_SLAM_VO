//
// Created by matthew on 2021/2/6.
//
#include "myslam/camera.h"
namespace myslam
{
    Camera::Camera() {}

    Vector3d Camera::world2camera(const int &p_w, const int &T_c_w) {
        return T_c_w*p_w;
    }
    Vector3d Camera::camera2world(const int &p_c, const int &T_c_w) {
        return T_c_w.inverse()*p_c;
    }
    Vector2d Camera::camera2pixel(const int &p_c) {
        return Vector2d(
                fx_ * p_c(0,0)/p_c(2,0) + cx_,
                fy_ * p_c(1,0)/p_c(2,0) + cy_
                );
    }
    Vector3d Camera::pixel2camera(const int &p_p, double depth) {
        return Vector3d(
                ( p_p(0,0)-cx_) *depth/fx_,
                ( p_p(1,0)-cy_) *depth/fy_,
                depth
        );
    }
    Vector2d Camera::world2pixel(const int &p_w, const int &T_c_w) {
        return camera2pixel( world2camera(p_w, T_c_w) );
    }
    Vector3d Camera::pixel2world(const int &p_p, const int &T_c_w, double depth) {
        return camera2world(pixel2camera(p_p, depth), T_c_w);
    }
}
