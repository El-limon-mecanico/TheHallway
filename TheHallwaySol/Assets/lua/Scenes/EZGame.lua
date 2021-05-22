EZGame = {
    entities = {"UI","sceneLight", "Player", "Maze"}
}

UI = {
    Active = true,
    Components = {"Health"},
    Health={
        MaxLives = 3
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
        SpecularColor = {0,0,0},
        Direction = {0,0,0},
        Distance = 1,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}


Player = {
    Active = true,
    Components = {"Transform", "MeshRenderer","Rigidbody","Light", "Lighter", "PlayerMovement"},

    Transform = {
        Position = {5,20,5},
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
        RotationConstrains = {1,1,1}
    },

    Light = {
        LightType = 2,
        DiffuseColor = {0,1,1},
        SpecularColor = {0,0,0},
        Direction = {0,0,1},
        Distance = 9000,
        InnerAngle = 35,
        OuterAngle = 50,
        isOn = true
    },
    Lighter ={
        ChargeSpeed = 0.15,
        DischargeSpeed = 0.08
    },
    
    PlayerMovement = 
    {
        WalkingSpeed = 10,
        RunningSpeed = 10,
        CameraSpeed = 100
    },

    Children ={
        entities={"defaultCamera"},

        defaultCamera = {

            Active = true,
            
            Components = {"Transform", "Camera"},
            
            Transform = {
                Position = {0,75,0},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },

            Camera = {
                Name = "MainCam",
                Background = {0,0,0},
                LookAt = {0,0,0},
                Width = 0,
                Height = 0,
                NearClipDistance = 1,
                FarClipDistance = 100000,
                ProjectionType = "Perspective"
            }
        }
    }
}

Maze = {
    Active = true,
    Components = {"Transform", "MazeManager"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    MazeManager = {
        Size = 10,
        Holes = 15,
        Levers = 3,
        ChargeVel = 1,
        UnchargeVel = 2
    }
}