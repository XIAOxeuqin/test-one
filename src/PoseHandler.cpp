 #include "PoseHandler.h"
#include<map>

 namespace adas {
 char directions[4] = {'N', 'E', 'S', 'W'};
 std::map<char, int> directions2index = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

 PoseHandler::PoseHandler(const Pose& pose) noexcept : m_Pose(pose) {}

 Pose PoseHandler::Query() const noexcept {
     return m_Pose;
 }

 void PoseHandler::Move() noexcept {
     if (IsFast()&&(!IsReverse())) {
         // Move twice if in fast mode
         if (m_Pose.heading == 'E') {
             m_Pose.x += 2;
         } else if (m_Pose.heading == 'W') {
             m_Pose.x -= 2;
         } else if (m_Pose.heading == 'N') {
             m_Pose.y += 2;
         } else if (m_Pose.heading == 'S') {
             m_Pose.y -= 2;
         }
     }

     if((!IsFast())&&IsReverse()){
         if (m_Pose.heading == 'E') {
             m_Pose.x--;
         } else if (m_Pose.heading == 'W') {
             m_Pose.x++;
         } else if (m_Pose.heading == 'N') {
             m_Pose.y--;
         } else if (m_Pose.heading == 'S') {
             m_Pose.y++;
         }
     }
     if((!IsFast())&&(!IsReverse())){
         if (m_Pose.heading == 'E') {
             m_Pose.x++;
         } else if (m_Pose.heading == 'W') {
             m_Pose.x--;
         } else if (m_Pose.heading == 'N') {
             m_Pose.y++;
         } else if (m_Pose.heading == 'S') {
             m_Pose.y--;
         }
     }
     if(IsFast()&&IsReverse()){
         if (m_Pose.heading == 'E') {
             m_Pose.x-=2;
         } else if (m_Pose.heading == 'W') {
             m_Pose.x+=2;
         } else if (m_Pose.heading == 'N') {
             m_Pose.y-=2;
         } else if (m_Pose.heading == 'S') {
             m_Pose.y+=2;
         }
     }
 }


 void PoseHandler::TurnLeft() noexcept {
     if(IsFast()&&(!IsReverse())) {
         Fast();
         Move();
         Fast();
     index = (index - 1+4) % 4;
     m_Pose.heading = directions[index];}

     if((!IsFast())&&(!IsReverse())) {
         index = (index - 1+4) % 4;
         m_Pose.heading = directions[index];}

     if(IsFast()&&IsReverse()) {
         Fast();
         Move();
         Fast();

         index = (index + 1) % 4;
         m_Pose.heading = directions[index];}
     if((!IsFast())&&IsReverse()) {

         index = (index + 1) % 4;
         m_Pose.heading = directions[index];}
 }

 void PoseHandler::TurnRight() noexcept {
     if(IsFast()&&(!IsReverse())) {
         Fast();//isFast=true
         Move();
         Fast();
         index = (index +1) % 4;
         m_Pose.heading = directions[index];}

     if((!IsFast())&&(!IsReverse())) {
         index = (index +1) % 4;
         m_Pose.heading = directions[index];}

     if(IsFast()&&IsReverse()) {
         Fast();
          Move();
          Fast();
         index = (index - 1+4) % 4;
         m_Pose.heading = directions[index];}
     if((!IsFast())&&IsReverse()) {

         index = (index -1+4) % 4;
         m_Pose.heading = directions[index];}
 }

 void PoseHandler::Fast() noexcept {
     isFast = !isFast;
 }

 void PoseHandler::Reverse() noexcept {
     isReverse = !isReverse;
 }

bool PoseHandler::IsFast()const noexcept{
    return isFast;
}

bool PoseHandler::IsReverse()const noexcept{
    return isReverse;
}

 }  // namespace adas
// Created by DELL on 2024/12/16.
//
