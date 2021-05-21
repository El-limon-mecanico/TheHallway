scene1 = {
    entities = {"defaultCamera", "Enemy", "sceneLight", "Maze", "Player"}
}

Enemy = {
    Active=true,
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
        Type = "Hull",
        Mass = 1,
        Trigger = true,
        Static = false,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },

    ChasePlayer = {
        Speed = 10
    }
}

defaultCamera = {
    Active = true,

    Components = {"Transform", "Camera"},

    Transform = {
        Position = {25,75,25},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Active = true,
        Name = "MainCam",
        Background = {1,1,0},
        LookAt = {5.75*20,0,5.75*20},
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
        Active = true,
        Position = {-10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        Active = true,
        LightType = 1,
        DiffuseColor = {0.1,0,0},
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 1,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}

Player = {
    Active = true,
    Components = {"Transform", "Light", "Lighter"},

    Transform = {
        Position = {10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        LightType = 2,
        DiffuseColor = {1,1,1},
        SpecularColor = {0,0,1},
        Direction = {1,0,1},
        Distance = 9000,
        InnerAngle = 35,
        OuterAngle = 50,
        isOn = true
    },
    Lighter ={
        ChargeSpeed = 0.15,
        DischargeSpeed = 0.08
    }

}

Maze = {
    Active = true,
    Components = {"Transform", "MazeManager"},
    Transform = {
        Active = true,
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    MazeManager = {
        Active = true,
        Size = 5,
        Holes = 200,
        Levers = 1,
        ChargeVel = 5,
        UnchargeVel = 2,
    }
}