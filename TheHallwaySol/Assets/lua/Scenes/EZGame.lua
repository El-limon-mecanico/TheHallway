EZGame = {
    entities = {"UI","defaultCamera","sceneLight", "Maze", "Player"}
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
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 1,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}

defaultCamera = {

    Active = true,
    
    Components = {"Transform", "Camera"},
    
    Transform = {
        Position = {50,150,50},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MainCam",
        Background = {0,0,0},
        LookAt = {50,0,50},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    }
}

Player = {
    Active = true,
    Components = {"Transform", "MeshRenderer","Rigidbody", "PlayerMovement"},

    Transform = {
        Position = {10,5,10},
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
        LightType = 0,
        DiffuseColor = {1,1,1},
        SpecularColor = {0,0,1},
        Direction = {0,0.5,1},
        Distance = 3000,
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
        Active = true,
        Size = 6,
        Holes = 10,
        Levers = 1,
        ChargeVel = 5,
        UnchargeVel = 2,
	    Ghosts = 1,
        Enemies = 1,
        PointsGhosts = 4,
        GhostRadar = 15,
        EnemyRadar = 20
    }
}