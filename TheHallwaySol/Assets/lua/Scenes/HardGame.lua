HardGame = {
    entities = {"defaultCamera", "sceneLight", "Maze"}
}

defaultCamera = {
    Active = true,
    Components = {"Transform", "Camera"},

    Transform = {
        Position = {25, 75,25},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MainCam",
        Background = {1,1,0},
        LookAt = {25,0,25},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    },
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

Maze = {
    Active = true,
    Components = {"Transform", "MazeManager"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    MazeManager = {
        Size = 30,
        Holes = 5,
        Levers = 3,
        ChargeVel = 1,
        UnchargeVel = 2
    }
}