HardGame = {
    entities = {"Player", "Maze", "Enemy"}
}

sceneLight = {
    Active = true,
    Components = {"Transform", "Light"},

    Transform = {
        Position = {0,10,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        LightType = 1,
        DiffuseColor = {0.3,0.3,0.3},
        SpecularColor = {0.3,0.3,0.3},
        Direction = {1,0,0},
        Distance = 1,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}


Player = {
    Active = true,
    Components = {"Transform", "MeshRenderer","Rigidbody","PlayerMovement", "Light", "Lighter", "Health"},

    Transform = {
        Position = {0,3,3},
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
        PositionConstrains = {0,1,0},
        RotationConstrains = {1,1,1}
    },

    Light = {
        LightType = 0,
        DiffuseColor = {1,1,1},
        SpecularColor = {1,1,1},
        Direction = {0,-1,0},
        Distance = 5000,
        InnerAngle = 35,
        OuterAngle = 60,
        isOn = true
    },
    Lighter ={
        ChargeSpeed = 0.3,
        DischargeSpeed = 0.08
    },
    
    PlayerMovement = 
    {
        WalkingSpeed = 10,
        RunningSpeed = 10,
        CameraSpeed = 200
    },
    Health={
        MaxLives = 3
    },

    Children ={
        entities={"defaultCamera"},

        defaultCamera = {

            Active = true,
            
            Components = {"Transform", "Camera", "CameraController"},
            
            Transform = {
                Position = {0,7,3},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },

            Camera = {
                Name = "MainCam",
                Background = {1,1,1},
                LookAt = {0,7,5},
                Width = 1,
                Height = 1,
                NearClipDistance = 1,
                FarClipDistance = 100000,
                ProjectionType = "Perspective"
            },
            CameraController = {}

        }
    }
}


Enemy = {
    Active=true,
    Tag = "Enemy",
    Components = {"Transform", "MeshRenderer", "LoopMovement","Rigidbody", "ChasePlayer"},

    Transform = {
        Position = {-10,0,0},
        Scale = {700,700,700},
        Rotation = {90,40,0}
    },

    MeshRenderer = {
        Mesh = "Icosphere.mesh",
    },

    LoopMovement = {
        Speed=10,
        Objectives={{-10,0,0},{51,0,0}, {51,0,51}, {0,0,51}},
        Distance = 15
    },
    Rigidbody = {
        Type = "Cube",
        Mass = 1,
        Trigger = true,
        Static = false,
        PositionConstrains = {0,1,0},
        RotationConstrains = {1,1,1}
    },

    ChasePlayer = {
        Speed = 10
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
        Size = 15,
        Holes = 5,
        Levers = 3,
        ChargeVel = 1,
        UnchargeVel = 2
    }
}