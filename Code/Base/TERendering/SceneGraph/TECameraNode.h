#ifndef TECAMERANODE_H
#define TECAMERANODE_H

#include <TENode.h>

namespace TE::SceneGraph {
  class Camera;

  class CameraNode : public Node {
  public:
    CameraNode(Camera &camera);
    virtual ~CameraNode();
    void SetCameraRef(Camera &camera);
    Camera &GetCamera() const;
    virtual void UpdateWorldData();

  private:
    void UpdateLocalTransformFromCamera(const Camera &camera);
    Camera &m_camera;
  };
}

#endif
