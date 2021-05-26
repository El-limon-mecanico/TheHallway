EZGame = {
    entities = {"Maze","Player", "Enemy", "Minimap"}
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
    Components = {"Transform", "MeshRenderer","Rigidbody","PlayerMovement", "Light", "Lighter", "Health","AudioListener"},

    Transform = {
        Position = {0,3,3},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Suzanne.mesh",
    },

    Rigidbody = {
        Type = "Box",
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
    AudioListener={},
    Children ={
        entities={"defaultCamera","LighterSound","WalkSound","RunSound","ScreamSounds"},

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
                Background = {0,0,0},
                LookAt = {0,7,5},
                Width = 1,
                Height = 1,
                xProp = 16,
                yProp = 9,
                NearClipDistance = 1,
                FarClipDistance = 100000,
                ProjectionType = "Perspective",
                zOrder = 1
            },

            CameraController = {}

        },
        LighterSound={
            Active=true,
            Components={"AudioSource"},
            AudioSource={
                Source= "ChargingLighter.wav",
                Volume=1,
                Loops=-1,
                Play=false,
                Enabled =true,
                D3=false
            }
        },
        WalkSound={
            Active=true,
            Components={"AudioSource"},
            AudioSource={
                Source= "Steps.ogg",
                Volume=1,
                Loops=-1,
                Play=false,
                Enabled =true,
                D3=false
            },
    },
    RunSound={
        Active=true,
        Components={"AudioSource"},
        AudioSource={
            Source= "LaRajaDeTuFalda.mp3",
            Volume=1,
            Loops=-1,
            Play=false,
            Enabled =true,
            D3=false
        },
},
ScreamSounds={
    Active=true,
    Components={},
    Children={
        entities={"GirlScream","BoyScream"},
        GirlScream={
            Active=true,
            Components={"AudioSource"},
            AudioSource={
                Source= "GirlScream.ogg",
                Volume=1,
                Loops=0,
                Play=false,
                Enabled =true,
                D3=false
            },
        },
        BoyScream={
            Active=true,
            Components={"AudioSource"},
            AudioSource={
                Source= "BoyScream.ogg",
                Volume=1,
                Loops=0,
                Play=false,
                Enabled =true,
                D3=false
            },
        },
    }
}
}
}


Enemy = {
    Active=true,
    Tag = "Enemy",
    Components = {"Transform", "MeshRenderer", "LoopMovement","Rigidbody", "ChasePlayer","AudioSource"},

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
        Type = "Box",
        Mass = 1,
        Trigger = true,
        Static = false,
        PositionConstrains = {0,1,0},
        RotationConstrains = {1,1,1}
    },

    ChasePlayer = {
        Speed = 10
    },
    AudioSource={
        Source= "Ghost.wav",
        Volume=4,
        Loops=-1,
        Play=false,
        Enabled =true,
        D3=true
    }
}

Maze = {
    Active = true,
    Components = {"Transform", "MazeManager","AudioSource"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MazeManager = {
        Active = true,
        Size = 6,
        Holes = 100,
        Levers = 1,
        ChargeVel = 5,
        UnchargeVel = 2,
        Ghosts = 0,
        Enemies = 1,
        PointsGhosts = 4,
        GhostRadar = 15,
        EnemyRadar = 20
    },
    AudioSource={
        Source= "TheHallway.wav",
        Volume=0.1,
        Loops=-1,
        Play=true,
    }
}

Minimap = 
{
    Active = true,
    Components = {"Transform", "Camera", "MinimapController", "Image"},
    
    Transform = {
        Position = {0,100,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MinimapCam",
        Background = {0,0,0},
        LookAt = {0,0,0},
        Top = 0.05,
        Left = 0.78,
        Width = 0.2,
        Height = 0.33,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective",
        zOrder = 0
    },

    MinimapController = {},

    Image = { 
        Active = true,
        Style= "TheHallway/StaticImage",
        Name = "MapFrame",
        Image = "MapFrame.png",
        Background = false,
        Border = false,
        Position = {0.776, 0.04},
        Size = {236, 220}
    }
}