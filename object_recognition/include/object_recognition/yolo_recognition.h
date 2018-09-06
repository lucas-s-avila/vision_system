#include "ros/ros.h"

#include <vector>
#include <string>

#include "darknet_ros_msgs/BoundingBoxes.h"
#include "vision_system_msgs/RecognizedObjects.h"
#include "vision_system_msgs/RecognizedPeople.h"

//A class that will set the parameters in rosparam server and make a interface of object_recognition and darknet_ros packages

class YoloRecognition{
    public:
        YoloRecognition(ros::NodeHandle _nh);

        void yoloRecognitionCallback(darknet_ros_msgs::BoundingBoxes bbs);

    private:
        ros::NodeHandle node_handle;

        ros::Subscriber bounding_boxes_sub;

        ros::Publisher recognized_objects_pub;
        ros::Publisher recognized_people_pub;
        
        std::string bounding_boxes_topic;
        int bounding_boxes_qs;

        std::string object_recognition_topic;
        int object_recognition_qs;

        std::string people_recognition_topic;
        int people_recognition_qs;

        std::string person_identifier;

        void readParameters();
};