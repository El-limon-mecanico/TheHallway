scene1 = {
    entities = {"defaultCamera","entidad1", "entidad2", "entidad3", "sceneLight"}
}

entidad1 = {

    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody", "PlayerMovement"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Suzanne.mesh",
    },

    Rigidbody = {
        Type = "Cube",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },

    PlayerMovement = 
    {
        WalkingSpeed = 500,
        RunningSpeed = 1000,
        cameraXSpeed = 100,
        cameraYSpeed = 0.75
    },

    Children={
        entities={"defaultCamera"},  

        defaultCamera = {

            Active = true,
            
            Components = {"Transform", "Camera"},
            
            Transform = {
                Position = {0,0,2},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },

            Camera = {
                Name = "MainCam",
                Background = {1,1,0},
                LookAt = {0,0,4},
                Width = 0,
                Height = 0,
                NearClipDistance = 1,
                FarClipDistance = 100000,
                ProjectionType = "Perspective"
            }
        }
    }

}

entidad2 = {

    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,-2,0},
        Scale = {60,60,1},
        Rotation = {-90,0,0}
    },

    MeshRenderer = {
        Mesh = "Plane",
    },

    Rigidbody = {
        Type = "Cube",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    }
}

entidad3 = 
{
    Active = true,

    Components = {"Transform", "MeshRenderer"},

    Transform = {
        Position = {0,0,4},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Suzanne.mesh",
    }
}

sceneLight = {

    Active = true,

    Components = {"Transform", "Light"},

    Transform = {
        Position = {-10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        LightType = 1,
        DiffuseColor = {1,1,1},
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 100,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}