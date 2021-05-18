scene1 = {
    entities = {"defaultCamera","player","sceneLight","Maze"}
}

defaultCamera = {
    Active = true,

    Components = {"Transform", "Camera"},

    Transform = {
        Position = {25, 80,25},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MainCam",
        Background = {0,0,0},
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
        Distance = 50,
        InnerAngle = 20,
        OuterAngle = 60,
        isOn = true
    }
}

player = {
    Active = true,
    Components = {"Transform", "Light", "Lighter"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        LightType = 2,
        DiffuseColor = {1,1,1},
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 2,
        InnerAngle = 20,
        OuterAngle = 60,
        isOn = true
    },
    Lighter ={
        ChargeSpeed = 0.01,
        DischargeSpeed = 0.03
    }

}

Maze = {
    Active = true,
    Components = {"Transform", "MazeCreator"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    MazeCreator = {
        Size = 15,
        Holes = 5
    }
}