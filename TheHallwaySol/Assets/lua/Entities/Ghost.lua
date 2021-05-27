Ghost = {
    Active=true,
    Tag = "Enemy",
    Components = {"Transform", "MeshRenderer", "LoopMovement","Rigidbody", "ChasePlayer","AudioSource"},

    Transform = {
        Position = {-10,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Ghost.mesh",
    },

    LoopMovement = {
        Speed=10,
        Objectives={},
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
